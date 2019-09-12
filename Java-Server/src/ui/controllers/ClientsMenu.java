package ui.controllers;

import com.jfoenix.controls.JFXTabPane;
import javafx.fxml.FXML;
import ui.widgets.ClientTab;

public class ClientsMenu {

    @FXML
    public JFXTabPane clientsTabPane;

    @FXML
    public void clientsLabelPressed() {
        createClientTab("Client");
    }

    public void createClientTab(String name) {
        ClientTab clientTab = new ClientTab(name);
        clientTab.load();

        clientsTabPane.getTabs().add(clientTab);
    }
}
