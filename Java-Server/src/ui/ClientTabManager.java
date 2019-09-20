package ui;

import game.Game;
import javafx.application.Platform;
import ui.controllers.ClientsMenu;

import java.util.ArrayList;
import java.util.List;

public class ClientTabManager {

    private static List<Game> games = new ArrayList<>();
    private static ClientsMenu clientsMenu;

    public static void createTab(Game game) {
        for (int i = 0; i < games.size(); i++){
            if (games.get(i).getId().equals(game.getId())) {
                games.set(i, game);
                return;
            }
        }
        games.add(game);
        loadTab(game);
    }

    private static void loadTab(Game game) {
        Platform.runLater(() -> {
            clientsMenu.createClientTab(String.valueOf(game.getId()));
            clientsMenu.setGame(game);
        });

    }

    public static void setClientsMenu(ClientsMenu clientsMenu) {
        ClientTabManager.clientsMenu = clientsMenu;
    }
}
