#include <iostream>
#include <string>
using namespace std;
int
main ()
{
  int op, recurso, id, prestamo, informacion_del_prestamo, recurso_prestado, recurso_numero;
  string estudiante;
  
  cout << "Bienvenido a la central de prestamos de la Universidad" << endl;
  do
	{
	  cout << "Ingresa:\n" <<
	    "1)agregar un recurso\n" <<
		"2)agregar un estudiante\n" << 
		"3)prestar un recurso dispinible\n" <<
		"4)consultar los prestamos de un estudiante\n" <<
		"5)consultar la informacion de un prestamo\n" <<
		"6)devolver un recurso prestado\n" << "7) salir\n" << endl;
	  cin >> op;

	  switch (op)
		{
		    case 1:
		        {
			      cout << "Agregar un recurso" << endl;
			      cout<< "ingrese numero del recurso"<<endl;
			      cin >> recurso;
			      cout << "Se agrego correctamente" << recurso << endl;
		         }break;

		     case 2:
		          {
			        cout << "Agregar un estudiante" << endl;
		         	cout << "Ingresar id estudiante: "<< endl;
			        cin >> id;
		            cout << "Ingresar el codigo del estudiante" << endl;
	                cin >> estudiante;
	                cout<<"se agrego correctamente el recurso numero" << estudiante << "con id" << id << endl;
 
		          }break;
	

               case 3:
                    {
	                    cout << "prestar un recurso disponible" << endl;
	                    cin >> recurso;
                    }break;
                case 4:
                     {
	                     cout << "consultar los prestamos de un estudiante" << endl;
	                     cin >> prestamo;
                      }break;
                      
                case 5:
                    {
	                    cout << "consultar la informacion de un prestamo" << endl;
	                    cin >> informacion_del_prestamo;
                    }break;
                    
                case 6:
                    {
                    	cout << "devolver un recurso prestado" << endl;
	                    cin >> recurso_prestado;

                    }break;
                    
                case 7:
                    {
	                     cout << "Gracias por utilizar la Central de prestamos" << endl;
                    }break;
 
                default:
                    {
	                     cout << "Ingresa una opciC3n vC!lida" << endl;
                    }break;
  
        }
	}while (op != 7);
  
        cout << "Ingresa:\n" << "1)agregar un recurso\n" <<
		"2)agregar un estudiante\n" << "3)prestar un recurso dispinible\n" <<
		"4)consultar los prestamos de un estudiante\n" <<
		"5)consultar la informacion de un prestamo\n" <<
		"6)devolver un recurso prestado\n" << "7) salir\n" << endl;
  return 0;
  
}
