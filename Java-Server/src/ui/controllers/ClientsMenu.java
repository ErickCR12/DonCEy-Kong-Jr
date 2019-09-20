package ui.controllers;

import com.jfoenix.controls.JFXTabPane;
import game.Game;
import javafx.fxml.FXML;
import ui.widgets.ClientTab;

public class ClientsMenu {

    @FXML
    public JFXTabPane clientsTabPane;

    private Game game;

    @FXML
    public void clientsLabelPressed() {
        createClientTab("Client");
    }

    public void createClientTab(String name) {
        ClientTab clientTab = new ClientTab(name);
        clientTab.load();

        clientsTabPane.getTabs().add(clientTab);
    }

    public void setGame(Game game) {
        this.game = game;
    }
}
