#include <iostream>
#include "ListArray.h"

int main(){
    std::cout << std::boolalpha; // configuramos cout para mostrar true/false en lugar de 0/1.

    ListArray<int> List;

    std::cout << List << std::endl; 
    std::cout << "size(): " << List.size() << std::endl; 
    std::cout << "empty(): " << List.empty() << std::endl; 
    std::cout << std::endl; 

    List.insert(0, 0);
    List.insert(1, 10);
    List.insert(0, -5);
    List.insert(2, 5);
    std::cout << List << std::endl; 
    std::cout << "size(): " << List.size() << std::endl; 
    std::cout << "empty(): " << List.empty() << std::endl; 
    std::cout << std::endl; 

    std::cout << "l.get(0) => " << List.get(0) << "; l[0] => " << List[0] << std::endl; 
    std::cout << "l.get(3) => " << List.get(3) << "; l[3] => " << List[3] << std::endl; 
    std::cout << std::endl; 

    int r;
    r = List.remove(3);
    std::cout << "l.remove(3) => " << r << ": " << std::endl; 
    r = List.remove(1);
    std::cout << "l.remove(1) => " << r << ": " << std::endl; 
    r = List.remove(0);
    std::cout << "l.remove(0) => " << r << ": " << std::endl; 
    std::cout << std::endl; 

    std::cout << List << std::endl; 
    std::cout << "size(): " << List.size() << std::endl; 
    std::cout << "empty(): " << List.empty() << std::endl; 
    std::cout << std::endl; 
   
    List.append(14);
    List.prepend(33);
    std::cout << List << std::endl; 
    std::cout << "size(): " << List.size() << std::endl; 
    std::cout << "empty(): " << List.empty() << std::endl; 
    std::cout << std::endl; 

    std::cout << "l.search(14) => " << List.search(14) << std::endl; 
    std::cout << "l.search(55) => " << List.search(55) << std::endl; 

    try{
        List.insert(-1, -99);
    } catch (std::out_of_range &e){
        std::cout << "l.insert(-1, 99) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        List.insert(4, -99);
    } catch (std::out_of_range &e){
        std::cout << "l.insert(4, 99) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        List.get(-1);
    } catch (std::out_of_range &e){
        std::cout << "l.get(-1) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        List.get(3);
    } catch (std::out_of_range &e){
        std::cout << "l.get(3) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        List.remove(-1);
    } catch (std::out_of_range &e){
        std::cout << "l.remove(-1) => std::out_of_range: " << e.what() << std::endl; 
    }

    try{
        List.remove(3);
    } catch (std::out_of_range &e){
        std::cout << "l.remove(3) => std::out_of_range: " << e.what() << std::endl; 
    }

}
