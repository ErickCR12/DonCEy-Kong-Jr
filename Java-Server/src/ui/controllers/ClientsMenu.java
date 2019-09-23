package ui.controllers;

import com.jfoenix.controls.JFXTabPane;
import game.Game;
import javafx.application.Platform;
import javafx.fxml.FXML;
import ui.widgets.ClientTab;

import java.util.ArrayList;
import java.util.List;

public class ClientsMenu {

    @FXML
    public JFXTabPane clientsTabPane;

    private Game game;
    private List<ClientTab> clientsTab = new ArrayList<>();

    @FXML
    public void clientsLabelPressed() {
        createClientTab("Client");
    }

    public void createClientTab(String name) {
        ClientTab clientTab = new ClientTab(name);
        clientTab.setGameId(name);
        clientTab.load();

        clientsTab.add(clientTab);
        clientsTabPane.getTabs().add(clientTab);
    }

    public void updateGameView() {
        Platform.runLater(() -> {
            for (ClientTab clientTab : clientsTab) {
                if (clientTab == null) continue;
                if (clientTab.getGameId().equals(game.getId().toString())) {
                    clientTab.updateGameView(game);
                    break;
                }
            }
        });
    }

    public void setGame(Game game) {
        this.game = game;
    }

    public List<ClientTab> getClientsTab() {
        return clientsTab;
    }
}
