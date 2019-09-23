import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;
import server.Server;
import ui.ClientTabManager;
import ui.controllers.ClientsMenu;


public class Main extends Application {

    private static Server server;
    private static Stage window;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("ui/resources/clients_menu.fxml"));
        Parent root = fxmlLoader.load();
        window = primaryStage;
        window.setTitle("Donkey Kong Jr");
        window.getIcons().add(new Image("res/icon.png"));
        window.setScene(new Scene(root, 1280, 960));
        window.setOnCloseRequest(event -> close());
        window.show();

        ClientsMenu cMenu = fxmlLoader.getController();
        ClientTabManager.setClientsMenu(cMenu);

        // Starts the server
        server = Server.getInstance(9999);
        server.start();
    }

    private static void close() {
        window.close();
        server.stop();
        Platform.exit();
        System.exit(0);
    }
}
