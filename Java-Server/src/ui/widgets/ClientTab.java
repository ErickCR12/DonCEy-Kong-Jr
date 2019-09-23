package ui.widgets;

import game.Croco;
import game.Fruit;
import game.Game;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Tab;
import javafx.scene.image.Image;
import javafx.scene.layout.Pane;
import javafx.util.Duration;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class ClientTab extends Tab {

    private String name;
    private Pane pane;
    private GameView gameView;
    private RadioButton autoButton;
    private String gameId;
    private Timeline killer;
    private List<Croco> crocos = new ArrayList<>();
    private List<Fruit> fruits = new ArrayList<>();

    public ClientTab(String name) {
        this.name = name;
        this.pane = new Pane();
    }

    public void load() {
        setText(name);
        loadSpawners();
        loadGameView();
        loadAutoButton();
        setContent(pane);
        startKiller();
    }

    public void updateGameView(Game game) {
        gameView.update(game);

        if (killer != null) killer.stop();
        startKiller();
    }

    private void close() {
        this.getTabPane().getTabs().remove(this);
    }

    private void loadAutoButton() {
        autoButton = new RadioButton("Auto");
        autoButton.relocate(900, 680);
        autoButton.setOnMousePressed(
                event -> autoButtonPressed(!autoButton.selectedProperty().getValue()));

        pane.getChildren().add(autoButton);
    }

    private void loadGameView() {
        gameView = new GameView(660, 460);
        gameView.relocate(310, 100);
        gameView.load();

        pane.getChildren().add(gameView);
    }

    private void loadSpawners() {
        Image crocoIcon = new Image("croco.png");
        Spawner croco = new Spawner(crocoIcon);
        croco.relocate(100, 600);
        croco.setClientTab(this);
        croco.setType("croco");
        croco.load();

        Image fruitIcon = new Image("fruit.png");
        Spawner fruit = new Spawner(fruitIcon);
        fruit.relocate(100, 720);
        fruit.setClientTab(this);
        fruit.setType("fruit");
        fruit.load();

        pane.getChildren().addAll(croco, fruit);
    }

    private void checkAutoButton() {
        new Timeline(new KeyFrame(
                Duration.seconds(2),
                e -> checkAutoButton())).play();

        if (autoButton.isSelected()) createRandomEntity();
    }

    private void createRandomEntity() {
        Random rand = new Random();
        int rope = rand.nextInt(9);
        boolean croco = rand.nextBoolean();

        if (croco)
            crocos.add(new Croco(crocos.size(), "croco", rope));
        else
            fruits.add(new Fruit(fruits.size(), "fruit", rope));
    }

    private void startKiller() {
        killer = new Timeline(new KeyFrame(
                Duration.seconds(5),
                e -> close()));
        killer.play();
    }

    private void autoButtonPressed(Boolean selected) {
        System.out.println(selected);
        checkAutoButton();
    }

    public GameView getGameView() {
        return gameView;
    }

    public String getGameId() {
        return gameId;
    }

    public void setGameId(String gameId) {
        this.gameId = gameId;
    }

    public List<Croco> getCrocos() {
        return crocos;
    }

    public void setCrocos(List<Croco> crocos) {
        this.crocos = crocos;
    }

    public List<Fruit> getFruits() {
        return fruits;
    }

    public void setFruits(List<Fruit> fruits) {
        this.fruits = fruits;
    }
}
