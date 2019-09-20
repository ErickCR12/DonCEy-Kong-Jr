package game;

import org.json.JSONObject;

public class Entity {
    private int id;
    private float x;
    private float y;
    private float rx;
    private float ry;
    private String type;

    void parse(String json) {
        JSONObject jsonObject = new JSONObject(json);
        id = jsonObject.getInt("id");
        rx = jsonObject.getFloat("x");
        ry = jsonObject.getFloat("y");
        type = jsonObject.getString("type");
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getX() {
        return x;
    }

    public void setX(float x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(float y) {
        this.y = y;
    }

    public float getRx() {
        return rx;
    }

    public void setRx(float rx) {
        this.rx = rx;
    }

    public float getRy() {
        return ry;
    }

    public void setRy(float ry) {
        this.ry = ry;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}
