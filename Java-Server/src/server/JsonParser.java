package server;
import game.Game;
import ui.ClientTabManager;


class JsonParser {

    static void parseGame(String json) {
        Game game = new Game();
        game.parse(json);
        ClientTabManager.createTab(game);
    }
}
