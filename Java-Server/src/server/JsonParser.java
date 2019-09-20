package server;
import game.Game;


class JsonParser {

    static void parseGame(String json) {
        Game.getInstance().parse(json);
    }
}
