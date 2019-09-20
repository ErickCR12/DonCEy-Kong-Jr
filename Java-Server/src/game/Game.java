package game;

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
        JSONObject jsonJunior = jsonEntities.getJSONObject("junior");
        Entity junior = new Entity();
        junior.parse(jsonJunior.toString());
        entities.add(junior);
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
