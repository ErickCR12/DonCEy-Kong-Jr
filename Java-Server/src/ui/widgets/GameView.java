package ui.widgets;


import javafx.scene.layout.Pane;

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
}
