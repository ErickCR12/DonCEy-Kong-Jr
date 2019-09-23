package ui;

import game.Game;
import javafx.application.Platform;
import javafx.scene.control.Tab;
import ui.controllers.ClientsMenu;
import ui.widgets.ClientTab;

import java.util.ArrayList;
import java.util.List;

public class ClientTabManager {

    private static List<Game> games = new ArrayList<>();
    private static ClientsMenu clientsMenu;

    public static void createTab(Game game) {
        for (int i = 0; i < games.size(); i++){
            if (games.get(i).getId().equals(game.getId())) {
                games.set(i, game);
                clientsMenu.setGame(game);
                clientsMenu.updateGameView();
                return;
            }
        }
        games.add(game);
        loadTab(game);
    }

    public static ClientTab searchClientTab(Integer gameID) {
        ClientTab clientTab = null;
        for (ClientTab tab : clientsMenu.getClientsTab()) {
            if ( tab.getGameId().equals(gameID.toString())) {
                clientTab = tab;
                break;
            }
        }
        return clientTab;
    }

    private static void loadTab(Game game) {
        Platform.runLater(() -> {
            clientsMenu.createClientTab(String.valueOf(game.getId()));
            clientsMenu.setGame(game);
            clientsMenu.updateGameView();
        });
    }

    public static void setClientsMenu(ClientsMenu clientsMenu) {
        ClientTabManager.clientsMenu = clientsMenu;
    }
}
