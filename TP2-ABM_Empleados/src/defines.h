#ifndef DEFINES_H_
#define DEFINES_H_

//sorting criteria
#define sort2 strcmp(list[i].lastName, list[j].lastName) > 0 || ( !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) > 0 ) || ( !strcmp(list[i].lastName, list[j].lastName) && !strcmp(list[i].name, list[j].name) && list[i].sector > list[j].sector )
#define sort3 strcmp(list[i].lastName, list[j].lastName) < 0 || ( !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) < 0 ) || ( !strcmp(list[i].lastName, list[j].lastName) && !strcmp(list[i].name, list[j].name) && list[i].sector < list[j].sector )
#define sort4 list[i].sector > list[j].sector || ( list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0 ) || ( list[i].sector == list[j].sector && !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) > 0 )
#define sort5 list[i].sector < list[j].sector || ( list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0 ) || ( list[i].sector == list[j].sector && !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) < 0 )

//success messages
#define msg00 "//      TO MANY RETRIES, ABORTED OPERATION      //"
#define msg01 "//      EMPLOYEES SUCCESSFULLY INITIALIZED      //"
#define msg02 "//      EMPLOYEE SUCCESSFULLY REGISTRATED       //"
#define msg03 "//        EMPLOYEE SUCCESSFULLY MODIFIED        //"
#define msg04 "//          VALUE SUCCESFULLY MODIFIED          //"
#define msg05 "//        EMPLOYEE SUCCESSFULLY WITHDRAWN       //"

//error messages
#define erroR "//  UNEXPECTED ERROR, CONTACT YOUR SYS. ADMIN   //"
#define err00 "//      THERE ARE NO REGISTERED EMPLOYEES       //"
#define err01 "//      ERROR WHILE INITIALIZING EMPLOYEES      //"
#define err02 "//     ERROR WHILE REGISTERING NEW EMPLOYEE     //"
#define err03 "//        ERROR WHILE MODIFYING EMPLOYEE        //"
#define err04 "//            VALUE WAS NOT MODIFIED            //"
#define err05 "//         EMPLOYEE WITHDRAWAL CANCELLED        //"

#endif /* DEFINES_H_ */
