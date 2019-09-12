package ui.widgets;

import javafx.scene.control.Tab;
import javafx.scene.image.Image;
import javafx.scene.layout.Pane;

public class ClientTab extends Tab {

    private String name;

    public ClientTab(String name) {
        this.name = name;
    }

    public void load() {
        setText(name);
        loadSpawners();
    }

    private void loadSpawners() {

        Image crocoIcon = new Image("croco.png");
        Spawner croco = new Spawner(crocoIcon);
        croco.relocate(100, 600);
        croco.load();

        Image fruitIcon = new Image("fruit.png");
        Spawner fruit = new Spawner(fruitIcon);
        fruit.relocate(100, 720);
        fruit.load();

        setContent(new Pane(croco, fruit));
    }
}
