# Mini-Libc

Roman Gabriel-Marian, 333CB

Pentru stringuri: https://www.gnu.org/software/libc/manual/html_node/String-and-Array-Utilities.html
Pentru numarul syscallurilor: https://filippo.io/linux-syscall-table/
*Pentru un motiv sau altul, daca apelam __NR_Whatever nu mi-l recunostea

Pentru orice syscall: https://sites.uclouvain.be/SystInfo/manpages/man2/open.2.html
*Basically dupa ce am aflat ca syscall-ul returneaza -errno, toate implementarile nu sunt altceva
decat un mic wrapper peste acel syscall + errno.

Pentru second/nanosecond, arhi-cunoscutul chatgpt

Pentru memory: syscallurile de mai sus 
*Pentru functia free am scos unele functii cu static din mem_list.h (forumul a spus ca se poate), 
respectiv functiil mem_list_extract si mem_list_free. Basically nu m-am mai folosit deloc de acel
mem_list_head, asa cum probabil era intentionat.