package game;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class Game {
    private Integer id = 0;
    private List<Entity> entities = new ArrayList<>();

    public void parse(String json) {
        JSONObject jsonObject = new JSONObject(json);
        id = jsonObject.getInt("game");

        JSONObject jsonEntities = jsonObject.getJSONObject("entities");

        // Parse Junior
        JSONObject jsonJunior = jsonEntities.getJSONObject("junior");
        Entity junior = new Entity();
        junior.parse(jsonJunior.toString());

        // Parse Key
        JSONObject jsonKey = jsonEntities.getJSONObject("key");
        Entity key = new Entity();
        key.parse(jsonKey.toString());

        // Parse Donkey
        JSONObject jsonDonkey = jsonEntities.getJSONObject("donkey");
        Entity donkey = new Entity();
        donkey.parse(jsonDonkey.toString());
        parseArray(jsonEntities.getJSONArray("platforms"));
        parseArray(jsonEntities.getJSONArray("ropes"));

        entities.add(junior);
        entities.add(key);
        entities.add(donkey);


    }

    private void parseArray(JSONArray jsonArray) {
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject jsonObject = jsonArray.getJSONObject(i);
            Entity entity = new Entity();
            entity.parse(jsonObject.toString());
            entities.add(entity);
        }
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public List<Entity> getEntities() {
        return entities;
    }

    public void setEntities(List<Entity> entities) {
        this.entities = entities;
    }
}
