import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;
import server.Server;


public class Main extends Application {

    private static Server server;
    private static Stage window;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("ui/resources/clients_menu.fxml"));
        window = primaryStage;
        window.setTitle("Donkey Kong Jr");
        window.getIcons().add(new Image("res/icon.png"));
        window.setScene(new Scene(root, 1280, 960));
        window.setOnCloseRequest(event -> close());
        window.show();

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
