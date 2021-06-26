#ifndef DATASTORE_H_
#define DATASTORE_H_

//mensajes que pueden repetirse a lo largo de programa
#define MSG00 "//                    Reintentos excedidos, operacion cancelada                     //"
#define ERR00 "//                  Error inesperado, contacte a su administrador                   //"
#define ERR01 "//                   Datos cargados con anterioridad, OP cancelada                  //"
//mensajes segun orden/opcion del menu
#define MSG10 "//                         Archivo CSV cargado exitosamente                         //"
#define ERR10 "//                             Error al leer archivo CSV                            //"
#define ERR11 "//                      PARSER TXT no pudo leer el archivo CSV                      //"
#define ERR12 "//                  CONTROLLER READ TXT no pudo leer el archivo CSV                 //"

#define MSG20 "//                         Archivo BIN cargado exitosamente                         //"
#define ERR20 "//                             Error al leer archivo BIN                            //"
#define ERR21 "//                      PARSER BIN no pudo leer el archivo BIN                      //"
#define ERR22 "//                    CONTROLLER BIN no pudo leer el archivo BIN                    //"

#define MSG30 "//                          Empleado cargado exitosamente                           //"
#define ERR30 "//                             Error al cargar empleado                             //"

#define MSG40 "//                         Empleado modificado exitosamente                         //"
#define ERR40 "//                            Error al modificar empleado                           //"

#define MSG50 "//                          Empleado removido exitosamente                          //"
#define ERR50 "//                             Error al remover empleado                            //"

#define TIT60 "//                                Lista de empleados                                //"
#define ERR60 "//                             Error al listar empleados                            //"

#define ERR70 "//                             Error al ordenar empleados                           //"

#define MSG80 "//                         Archivo CSV guardado exitosamente                        //"
#define ERR80 "//                            Error al guardar archivo CSV                          //"
#define ERR81 "//                CONTROLLER WRITE TXT no guardar leer el archivo CSV               //"

#define MSG90 "//                         Archivo BIN guardado exitosamente                        //"
#define ERR90 "//                            Error al guardar archivo BIN                          //"
#define ERR91 "//                CONTROLLER WRITE BIN no pudo guardar el archivo BIN               //"

#endif /* DATASTORE_H_ */
