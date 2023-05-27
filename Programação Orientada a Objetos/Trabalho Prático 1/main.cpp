#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
#include "imovel.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

/**
 * Função para processar a linha lida do arquivo e a transformar em um vetor de strings
 */
std::vector<std::string> processString(std::string &s){

    //Sintaxe Remove e Erase para remover o \n do final da linha
    s.erase(remove(s.begin(), s.end(), '\n'), s.end());
    std::vector<std::string> result;
    std::istringstream iss(s);

    //Tokenização da string para separar por ;
    for(std::string token; std::getline(iss, token, ';');){
        result.push_back(move(token));
    }

    return result;
}

/**
 * Função para carregar os dados do arquivo para a o vetor
 */
void loadFile(std::vector<Imovel*> &imoveis){
    std::vector<std::string> data;
    std::string line;
    std::ifstream file("database_imoveis.txt");
    int id_count = 0;
    while(getline(file, line)){
        //Convertendo string em um vetor
        data = processString(line);
        //Caso a linha seja um apartamento, será criado um novo objeto e adicionado no vetor
        if(data[0] == "apartamento"){
            imoveis.push_back(new Apartamento(id_count,
                                                stof(data[1]),
                                                data[2],
                                                data[3],
                                                data[4],
                                                data[5],
                                                stoi(data[6]),
                                                stoi(data[7]),
                                                stoi(data[8]),
                                                stoi(data[9]),
                                                stof(data[10]),
                                                stoi(data[11]),
                                                stoi(data[12])));
        //Adicionando o objeto casa
        }else if(data[0] == "casa"){
            imoveis.push_back(new Casa(id_count,
                                        stof(data[1]),
                                        data[2],
                                        data[3],
                                        data[4],
                                        data[5],
                                        stoi(data[6]),
                                        stoi(data[7]),
                                        stoi(data[8]),
                                        stoi(data[9]),
                                        stoi(data[10])));

        //Adicionando o objeto chacara
        }else if(data[0] == "chacara"){
            imoveis.push_back(new Chacara (id_count,
                                            stof(data[1]),
                                            data[2],
                                            data[3],
                                            data[4],
                                            data[5],
                                            stoi(data[6]),
                                            stoi(data[7]),
                                            stoi(data[8]),
                                            stoi(data[9]),
                                            stoi(data[10]),
                                            stoi(data[11]),
                                            stoi(data[12]),
                                            stoi(data[13])));
        }
        id_count++;
    }

    file.close();
}

/**
 * 2- Função para verificar se um proprietário existe na coleção
 */
bool checkProprietario(std::vector<Imovel*> &imoveis, std::string proprietario){
    std::vector<Imovel*> result;

    for(int i=0;i<imoveis.size();i++){
        if(imoveis[i]->getProprietario() == proprietario){
            return true;
        }
    }

    return false;
}

/**
 * 3- Função para filtrar imóveis pelo valor
 */
std::vector<Imovel*> filterValor(std::vector<Imovel*> &imoveis, double valor){
    std::vector<Imovel*> result;

    for(int i=0;i<imoveis.size();i++){
        if(imoveis[i]->getValor() <= valor){
            result.push_back(imoveis[i]);
        }
    }

    return result;
}

/**
 * 4- Função para filtrar imóveis pelo número de quartos
 */
std::vector<Imovel*> filterQuartos(std::vector<Imovel*> &imoveis, int quartos){
    std::vector<Imovel*> result;

    for(int i=0;i<imoveis.size();i++){
        if(imoveis[i]->getQuartos() >= quartos){
            result.push_back(imoveis[i]);
        }
    }

    return result;
}

/**
 * 5- Função para filtrar imóveis pelo tipo
 */
std::vector<Imovel*> filterTipo(std::vector<Imovel*> &imoveis, std::string tipo){
    std::vector<Imovel*> result;

    for(int i=0;i<imoveis.size();i++){
        //Fazendo downcasting para verificar se o objeto é um apartamento
        if(tipo == "apartamento" && dynamic_cast<Apartamento*>(imoveis[i]) != nullptr){
            result.push_back(imoveis[i]);
        }
        //Fazendo downcasting para verificar se o objeto é um casa
        if(tipo == "casa" && dynamic_cast<Casa*>(imoveis[i]) != nullptr){
            result.push_back(imoveis[i]);
        }
        //Fazendo downcasting para verificar se o objeto é um chacara
        if(tipo == "chacara" && dynamic_cast<Chacara*>(imoveis[i]) != nullptr){
            result.push_back(imoveis[i]);
        }
    }

    /**
     * Ordenando o vetor com o método sort utilizando como critério o valor
     * Para realizar isso é necessário passar uma função de comparação é isso
     * foi feito utilizando uma expressão lambda
     */
    std::sort(result.begin(), result.end(), [](const Imovel *l, const Imovel *r){
        return l->getValor() < r->getValor();
    });

    return result;
}

/**
 * 6- Função para filtrar imóveis pela cidade
 */
std::vector<Imovel*> filterCidade(std::vector<Imovel*> &imoveis, std::string cidade){
    std::vector<Imovel*> result;

    for(int i=0;i<imoveis.size();i++){
        if(imoveis[i]->getCidade() == cidade){
            result.push_back(imoveis[i]);
        }
    }

    /**
     * Ordenando o vetor com o método sort utilizando como critério o valor
     * Para realizar isso é necessário passar uma função de comparação é isso
     * foi feito utilizando uma expressão lambda
     */
    std::sort(result.begin(), result.end(), [](const Imovel *l, const Imovel *r){
        return l->getValor() > r->getValor();
    });

    return result;
}

/**
 * 7- Função que retorna um iterador para cada tipo de imóvel que um proprietário tenha
 * Esse retorno é feito com um map do tipo <std::string, std::vector<Imovel*>::iterator>
 */
std::map<std::string, std::vector<std::vector<Imovel*>::iterator>> filterProprietario(std::vector<Imovel*> &imoveis, std::string proprietario){
    //Inicializando o map com o iterador imoveis.end(), caso não seja encontrado nenhum imovel deste tipo, esse sera o valor retornado
    std::vector<std::vector<Imovel*>::iterator> im;
    std::map<std::string, std::vector<std::vector<Imovel*>::iterator>> result { {"apartamento", im}, {"casa", im}, {"chacara", im}  };
    std::vector<Imovel*>::iterator ptr;

    for(ptr = imoveis.begin(); ptr < imoveis.end(); ptr++){
        //Verificando se o apartamento é do proprietário
         if((*ptr)->getProprietario() == proprietario && dynamic_cast<Apartamento*>(*ptr) != nullptr){
            result["apartamento"].push_back(ptr);
        }
        //Verificando se a casa é do proprietário
        if((*ptr)->getProprietario() == proprietario && dynamic_cast<Casa*>(*ptr) != nullptr){
            result["casa"].push_back(ptr);
        }
        //Verificando se a chacara é do proprietário
        if((*ptr)->getProprietario() == proprietario && dynamic_cast<Chacara*>(*ptr) != nullptr){
            result["chacara"].push_back(ptr);
        }
    }

    return result;
}

/**
 * 8- Método de saída
 * Caso mode seja 0 será utilizado o terminal
 * Caso mode seja 1 será utilizado um arquivo de texto
 */
void displayImovel(std::vector<Imovel*> &imoveis, int mode){
    if(mode == 0){
        for(int i=0;i<imoveis.size();i++){
            std::cout << *imoveis[i] << std::endl;
        }
    }
    if(mode == 1){
        std::ofstream file("saida.txt");
        for(int i=0;i<imoveis.size();i++){
            file << *imoveis[i] << std::endl;
        }
        file.close();
    }
}

/**
 * Instruções de execução utilizando Makefile: make all
 * Instruções de execução sem Makefile:
 * g++ main.cpp imovel.cpp apartamento.cpp casa.cpp chacara.cpp -o main
 * ./main 
 */

int main(){
    //Coleção polimórfica de imóveis
    std::vector<Imovel*> imoveis;
    loadFile(imoveis);

    //2
    std::string proprietario = "Kurt Turnbull";
    bool proprietario_encontrado = checkProprietario(imoveis, proprietario);
    //(proprietario_encontrado) ? std::cout << "Proprietário encontrado!" << std::endl : std::cout << "Proprietário não foi encontrado." << std::endl;

    //3
    double max_valor = 200000.0;
    std::vector<Imovel*> imoveis_filtro_valor = filterValor(imoveis, max_valor);
    //displayImovel(imoveis_filtro_valor, 0);

    //4
    int min_quartos = 5;
    std::vector<Imovel*> imoveis_filtro_quartos = filterQuartos(imoveis, min_quartos);
    //displayImovel(imoveis_filtro_quartos, 0);

    //5
    std::string tipo = "apartamento";
    std::vector<Imovel*> imoveis_filtro_tipo = filterTipo(imoveis, tipo);
    //displayImovel(imoveis_filtro_tipo, 0);

    //6
    std::string cidade = "Thompson";
    std::vector<Imovel*> imoveis_filtro_cidade = filterCidade(imoveis, cidade);
    //displayImovel(imoveis_filtro_cidade, 0);

    //7
    std::string proprietario2 = "Libbie Reilly";
    std::map<std::string, std::vector<std::vector<Imovel*>::iterator>> imoveis_filtro_proprietario = filterProprietario(imoveis, proprietario2);
    //Verificando se foi encontrado um apartamento no nome do proprietario
    /**
    if(imoveis_filtro_proprietario["apartamento"].size() == 0) std::cout << "Apartamento não foi encontrado." << std::endl;
    for(auto ptr : imoveis_filtro_proprietario["apartamento"]){
        std::cout << **ptr << std::endl;
    }

    //Verificando se foi encontrado uma casa no nome do proprietario
    if(imoveis_filtro_proprietario["casa"].size() == 0) std::cout << "Casa não foi encontrada." << std::endl;
    for(auto ptr : imoveis_filtro_proprietario["casa"]){
        std::cout << **ptr << std::endl;
    }

    //Verificando se foi encontrado uma chacara no nome do proprietario
    if(imoveis_filtro_proprietario["chacara"].size() == 0) std::cout << "Chacara não foi encontrada." << std::endl;
    for(auto ptr : imoveis_filtro_proprietario["chacara"]){
        std::cout << **ptr << std::endl;
    }
    */

    //8
    //displayImovel(imoveis, 0);
    return 0;
}
