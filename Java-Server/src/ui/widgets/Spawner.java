package ui.widgets;


import com.jfoenix.controls.JFXButton;
import game.Croco;
import game.Fruit;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;

public class Spawner extends Pane {

    private Image icon;
    private Integer width;
    private Integer height;
    private String type;
    private ClientTab clientTab;
    private String css;

    public Spawner(Image icon) {
        this.icon  = icon;
        this.width = 780;
        this.height = 80;
        this.css = "leaf.css";
    }

    public void load() {
        resize(width, height);
        getStylesheets().add(css);
        getStyleClass().add("spawner");

        loadIcon();
        loadButtons();
    }

    private void loadButtons() {
        Integer buttonsCount = 9;
        HBox hBox = new HBox(14);
        hBox.relocate(100, 8);
        getChildren().add(hBox);

        for (int i = 0; i < buttonsCount; i++) {
            // Creates the button
            Integer finalI = i;
            JFXButton button = new JFXButton(String.valueOf(i + 1));
            button.getStylesheets().add(css);
            button.setOnMousePressed(event -> mouseEvent(finalI));

            hBox.getChildren().add(button);
        }
        hBox.getChildren().add(new Label());
    }

    private void loadIcon() {
        Integer iconWidth = 76;
        Integer iconHeight = 66;

        ImageView imgView = new ImageView(icon);
        imgView.setFitWidth(iconWidth);
        imgView.setFitHeight(iconHeight);

        getChildren().add(imgView);
    }

    private void mouseEvent(Integer button) {
        System.out.printf("Spawner button pressed: %d \n", button);
        Integer size;
        switch (type) {
            case "croco":
                size = clientTab.getCrocos().size();
                clientTab.getCrocos().add(size, new Croco(size, "croco", button));
                break;
            case "fruit":
                size = clientTab.getFruits().size();
                clientTab.getFruits().add(size, new Fruit(size, "fruit", button));
                break;
        }
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public ClientTab getClientTab() {
        return clientTab;
    }

    public void setClientTab(ClientTab clientTab) {
        this.clientTab = clientTab;
    }
}
