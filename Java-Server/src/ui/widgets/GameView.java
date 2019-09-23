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

            ImageView imgView = chooseImg(entity, x, y);
            if (entity.getType().equals("rope")) continue;

            this.getChildren().add(imgView);
        }
    }

    private ImageView chooseImg(Entity entity, float x, float y) {
        String url= "";
        switch (entity.getType()) {
            case "junior":
                url = "monkey.png";
                break;
            case "donkey":
                url = "donkey.png";
                break;
            case "key":
                url = "key.png";
                break;
            case "fruit":
                url = "fruit.png";
                break;
            case "croco":
                url = "croco.png";
                break;
            case "platform":
                url = "cube.png";
                break;
            case "rope":
                url = "cube.png";
                return null;
        }

        ImageView imgView = new ImageView(url);
        imgView.relocate(x, y);
        imgView.setFitWidth(entity.getWidth());
        imgView.setFitHeight(entity.getHeight());
        if(entity.getType().equals("rope") || entity.getType().equals("platform"))
            imgView.setStyle("-fx-opacity: 0.5");

        return imgView;
    }
}
