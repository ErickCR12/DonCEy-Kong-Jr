package ui.controllers;

import com.jfoenix.controls.JFXTabPane;
import game.Game;
import javafx.application.Platform;
import javafx.fxml.FXML;
import ui.widgets.ClientTab;

public class ClientsMenu {

    @FXML
    public JFXTabPane clientsTabPane;

    private Game game;
    private ClientTab clientTab;

    @FXML
    public void clientsLabelPressed() {
        createClientTab("Client");
    }

    public void createClientTab(String name) {
        clientTab = new ClientTab(name);
        clientTab.load();

        clientsTabPane.getTabs().add(clientTab);
    }

    public void updateGameView() {
        Platform.runLater(() -> {
            clientTab.getGameView().update(game);
        });
    }

    public void setGame(Game game) {
        this.game = game;
    }
}
