package game;

import org.json.JSONObject;

public class Entity {
    protected int id;
    protected String type;
    private float x;
    private float y;
    private float rx;
    private float ry;
    private float width;
    private float height;

    public Entity() {
        this.id = 0;
        this.type = "";
        this.x = 0;
        this.y = 0;
        this.rx = 0;
        this.ry = 0;
        this.width = 0;
        this.height = 0;
    }

    public Entity(Integer id, String type) {
        this.id = id;
        this.type = type;
        this.x = 0;
        this.y = 0;
        this.rx = 0;
        this.ry = 0;
        this.width = 0;
        this.height = 0;
    }

    void parse(String json) {
        JSONObject jsonObject = new JSONObject(json);
        id = jsonObject.getInt("id");
        rx = jsonObject.getFloat("x");
        ry = jsonObject.getFloat("y");
        type = jsonObject.getString("type");
        width = jsonObject.getFloat("width");
        height = jsonObject.getFloat("height");
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

    public float getWidth() {
        return width;
    }

    public void setWidth(float width) {
        this.width = width;
    }

    public float getHeight() {
        return height;
    }

    public void setHeight(float height) {
        this.height = height;
    }
}
