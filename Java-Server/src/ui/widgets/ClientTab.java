package ui.widgets;

import javafx.scene.control.RadioButton;
import javafx.scene.control.Tab;
import javafx.scene.image.Image;
import javafx.scene.layout.Pane;

public class ClientTab extends Tab {

    private String name;
    private Pane pane;

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
    }

    private void loadAutoButton() {
        RadioButton radioButton = new RadioButton("Auto");
        radioButton.relocate(900, 680);
        radioButton.setOnMousePressed(
                event -> autoButtonPressed(!radioButton.selectedProperty().getValue()));

        pane.getChildren().add(radioButton);
    }

    private void loadGameView() {
        GameView gameView = new GameView(660, 460);
        gameView.relocate(310, 400);
        gameView.load();

        pane.getChildren().add(gameView);
    }

    private void loadSpawners() {
        Image crocoIcon = new Image("croco.png");
        Spawner croco = new Spawner(crocoIcon);
        croco.relocate(100, 600);
        croco.load();

        Image fruitIcon = new Image("fruit.png");
        Spawner fruit = new Spawner(fruitIcon);
        fruit.relocate(100, 720);
        fruit.load();

        pane.getChildren().addAll(croco, fruit);
    }

    private void autoButtonPressed(Boolean selected) {
        System.out.printf("Auto button status: %b \n", selected);
    }
}
