package ui.widgets;


import game.Entity;
import game.Game;
import javafx.application.Platform;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;

import java.util.List;

public class GameView extends Pane {

    private Integer width;
    private Integer height;
    private String css;

    public GameView(Integer width, Integer height) {
        this.width = width;
        this.height = height;
        this.css = "leaf.css";
    }

    public void load() {
        resize(width, height);
        getStylesheets().add(css);
        getStyleClass().add("game-view");
    }

    public void update(Game game) {
        this.getChildren().clear();
        List<Entity> entities = game.getEntities();
        for (Entity entity : entities) {
            float x = entity.getRx() * width;
            float y = entity.getRy() * height;

            ImageView monkey = new ImageView("monkey.png");
            monkey.relocate(x, y);
            monkey.setFitWidth(50);
            monkey.setFitHeight(50);

            this.getChildren().add(monkey);
        }
    }
}
