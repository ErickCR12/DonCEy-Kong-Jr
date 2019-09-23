package server;
import game.Croco;
import game.Fruit;
import game.Game;
import org.json.JSONArray;
import org.json.JSONObject;
import ui.ClientTabManager;
import ui.widgets.ClientTab;

/**
 * Manages the parse and serialization of the Game
 * @author José Acuña
 */
class JsonParser {

    /**
     * Creates a Game object with the given json string
     * last modified: 20 Set by Jose Acuna
     * @param json the string to parse
     * @return the gameID as Integer
     */
    static Integer parseGame(String json) {
        Game game = new Game();
        game.parse(json);
        ClientTabManager.createTab(game);
        return game.getId();
    }

    /**
     * Creates a Json String for the crocos and fruits
     * last modified: 20 Set by Jose Acuna
     * @param gameId the game client to send the json
     * @return Json String
     */
    static String serializeGame(Integer gameId) {
        ClientTab clientTab = ClientTabManager.searchClientTab(gameId);
        if (clientTab == null) return "";

        // Crocos
        JSONArray crocosArray = new JSONArray();
        for (Croco croco : clientTab.getCrocos()) {
            crocosArray.put(croco.serialize());
        }
        clientTab.getCrocos().clear();

        // Fruits
        JSONArray fruitsArray = new JSONArray();
        for (Fruit fruit : clientTab.getFruits()) {
            fruitsArray.put(fruit.serialize());
        }
        clientTab.getFruits().clear();

        JSONObject jsonObject = new JSONObject();
        jsonObject.put("crocos", crocosArray);
        jsonObject.put("fruits", fruitsArray);

        return jsonObject.toString();
    }
}
