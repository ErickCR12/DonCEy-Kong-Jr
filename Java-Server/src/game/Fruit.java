package game;

import org.json.JSONObject;

public class Fruit extends Entity {

    private Integer rope;

    public Fruit(Integer id, String type, Integer rope) {
        super(id, type);
        this.rope = rope;
    }

    public JSONObject serialize() {
        return new JSONObject(this);
    }

    public Integer getRope() {
        return rope;
    }

    public void setRope(Integer rope) {
        this.rope = rope;
    }
}
