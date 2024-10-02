#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<gtk/gtk.h>


std::vector<std::string> palabras = {"Piedra", "Papel", "Tijeras"};

void mmain();

void sumar(double a, double e);
void restar(double a, double e);
void multi(double a, double e);
void divi(double a, double e);
void calcu();
void pal_ale();

// Función que se ejecuta cuando se presiona el botón
static void on_button_clicked(GtkWidget *widget, gpointer data) {
  mmain();
}

// Función que se ejecuta cuando se cierra la ventana
static void on_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit(); // Termina el bucle principal de GTK
}



int main(int argc, char *argv[]) {
  // Inicializar GTK
    gtk_init(&argc, &argv);

    // Crear una nueva ventana
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Programa en C++ creado por Hugo González Ruiz de 1 ESO D(yo)");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300); // Tamaño inicial de la ventana

    // Conectar la señal de cerrar la ventana
    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    // Crear un contenedor vertical
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10); // Espacio de 10 píxeles entre los elementos
    gtk_container_add(GTK_CONTAINER(window), box); // Añadir la caja a la ventana

    // Crear un botón
    GtkWidget *button = gtk_button_new_with_label("Iniciar programa de terminal");

    // Ajustar el tamaño del botón
    gtk_widget_set_size_request(button, 200, 80); // Tamaño del botón: ancho 200, alto 80

    // Conectar el botón a la función on_button_clicked
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Añadir el botón a la caja sin expandirlo
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, TRUE, 0); // Añadir el botón a la caja

    // Aplicar estilo CSS para el fondo amarillo
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, "window { background-color: yellow; }", -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(css_provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Mostrar todos los widgets de la ventana
    gtk_widget_show_all(window);

    // Iniciar el bucle principal de GTK
    gtk_main();

}

void sumar(double a, double e) {
  double operacion = a + e;
  std::cout<<"El resultado de la suma es: "<< operacion;
  std::cout<<"\n";
}
void restar(double a, double e) {
  double operacion = a - e;
  std::cout<<"El resultado de la resta es: "<< operacion;
  std::cout<<"\n";
}
void multi(double a, double e) {
  double operacion = a * e;
  std::cout<<"El resultado de la multiplicación es: "<< operacion;
  std::cout<<"\n";
}
void divi(double a, double e) {
  double operacion = a / e;
  std::cout<<"El resultado de la división es: "<< operacion;
  std::cout<<"\n";
}

void calcu() {
  double num1;
  char operador;
  double num2;
  std::cout<<"Introduce el primer número:";
  std::cin>>num1;
  std::cout<<"Introduce el operador(+, -, *, /)";
  std::cin>>operador;
  std::cout<<"Dime el último número:";
  std::cin>>num2;
  if(operador == '+') {
    sumar(num1, num2);
    std::cout<<"\n\n------------------------------------\n\n";

  } else if(operador == '-') {
    restar(num1, num2);
    std::cout<<"\n\n------------------------------------\n\n";

  } else if(operador == '*') {
    multi(num1, num2);
    std::cout<<"\n\n------------------------------------\n\n";

  } else if(operador == '/') {
    divi(num1, num2);
    std::cout<<"\n\n------------------------------------\n\n";

  } else {
    std::cout<<"Operador erróneo.";
  }
}

void pal_ale() {
    std::string entradapal;

    srand(time(0));

    std::cout<<"Di Piedra, Papel o Tijeras.";
    std::cin>>entradapal;
    std::cout<<"\n";

    int indice_aleatorio = rand() % palabras.size();
    std::string palabraAleatoria = palabras[indice_aleatorio];

    if(entradapal == palabraAleatoria) {
      std::cout<<"Los dos hemos adivinado lo mismo: yo dije "<< palabraAleatoria<<" y tú "<< entradapal<<"\n\n";
      std::cout<<"---------------------------------------------------------------------------------------------\n\n";
    } else if(entradapal == "Piedra" && palabraAleatoria == "Papel")  {
      std::cout<<"He ganado, tú has dicho "<< entradapal<<" y yo "<< palabraAleatoria<<"\n\n";
      std::cout<<"---------------------------------------------------------------------------------------------\n\n";

    } else if(entradapal == "Papel" && palabraAleatoria == "Tijeras") {
      std::cout<<"He ganado, tú has dicho "<< entradapal<<" y yo "<< palabraAleatoria<<"\n\n";
      std::cout<<"---------------------------------------------------------------------------------------------\n\n";

    } else if(entradapal == "Tijeras" && palabraAleatoria == "Piedra") {
      std::cout<<"He ganado, tú has dicho "<< entradapal<<" y yo "<< palabraAleatoria<<"\n\n";
      std::cout<<"---------------------------------------------------------------------------------------------\n\n";

    } else if(entradapal == "Papel" && palabraAleatoria == "Piedra") {
      std::cout<<"Has ganado, tú has dicho "<< entradapal<< " y yo "<< palabraAleatoria<<"\n\n";
      std::cout<<"---------------------------------------------------------------------------------------------\n\n";

    } else if(entradapal == "Tijeras" && palabraAleatoria == "Papel") {
      std::cout<<"Has ganado, tú has dicho "<< entradapal<<" y yo "<< palabraAleatoria<<"\n\n";
      std::cout<<"---------------------------------------------------------------------------------------------\n\n";

    } else if(entradapal == "Piedra" && palabraAleatoria == "Tijeras") {
      std::cout<<"Has ganado, tú has dicho "<< entradapal<<" y yo "<< palabraAleatoria<<"\n\n";
      std::cout<<"---------------------------------------------------------------------------------------------\n\n";

    } else {
      std::cout<<"Hubo un error al leer la entrada, comprueba la palabra que has puesto, la palabra tiene que tener la primera letra en mayúscula y sin espacios.\n\n";
    }
}

void mmain() {
  std::string opcion;
  while(true) {
    std::cout<<"Bienvenido Carlos .J, soy Hugo, aquí te presento un programa en C++ que tiene 189 líneas de código, y también se los presento a mis compañeros que me están viendo ahora XD\n\n";
    std::cout<<"Elige una opción: 1(calculadora en terminal) o 2(juego de piedra papel o tijeras en terminal)";
    std::cin>>opcion;
    std::cout<<"\n";
    if(opcion == "1") {
      calcu();

    } else if(opcion == "2") {
      pal_ale();

    } else {
      std::cout<<"Error al leer la línea, tienes que introducer una entrada válida.\n\n";
      mmain();
    }
  }
}
