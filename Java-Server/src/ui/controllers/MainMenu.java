package ui.controllers;


import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.layout.Pane;
import ui.widgets.Spawner;

public class MainMenu {

    @FXML
    public Pane pane;

    public MainMenu() {

    }

    @FXML
    public void init() {
        Image icon = new Image("croco.png");
        Spawner spawner = new Spawner(icon);
        spawner.relocate(200, 200);
        spawner.load();

        pane.getChildren().add(spawner);
    }


}
