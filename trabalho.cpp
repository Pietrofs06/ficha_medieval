#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <time.h>
#include <chrono>
#include <thread>

using namespace std;

int main(){
    string nome, aparencia, sexo, classe, classeSocial, ocupacao, motivacao, estiloDeLuta, espadaDoPlayer, historia;
    int idade, ocupacaoEscolhida;
    int limiteDeClasses = 5;
    int limiteDeOcupacao = 4;
    int qStats = 6;
    int limiteDeClassesSociais = 10;
    
    int gerarClasseNum = rand() %limiteDeClasses;
    int gerarClasseSNum = rand() %limiteDeClassesSociais;
    
    string classes[limiteDeClasses] = {
        "Assassino",
        "Berserk",
        "Guerreiro",
        "Mago",
        "Curandeiro",  
    };
    string estilosDeLuta[limiteDeClasses] = {
        "Shadow Boxing",
        "Berzerker Mode",
        "Sword Combat",
        "Magic",
        "Kick Boxing", 
    };
    string classesSocial[limiteDeClassesSociais] = {
        "Clero",
        "Monarca",
        "Nobre",
        "Cavaleiro",
        "Vassalo",
        "Mercador",  
        "Fazendeiro", 
        "Artesão", 
        "Campones",
        "Servo",
    };
    string espadas[limiteDeClassesSociais] = {
        "Dragonslayer",
        "Banesword",
        "Greatsword",
        "Lightsaber",
        "Cavairy Sword",
        "Épée.",  
        "Rapier", 
        "Gold Sword", 
        "Weak Katana",
        "Wooden Sword",
    };
    string ocupacoes[limiteDeOcupacao] = {
        "Caçador",
        "Médico",
        "Ferriero",
        "Guarda Real",
    };
    string statusName[qStats] = {
        "Força: ",
        "Destreza: ",
        "Inteligência: ",
        "Persuasão: ",
        "Sabedoria: ",
        "Carisma: ",
    };
    int baseStats[qStats] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    string motivacoes[limiteDeOcupacao] = {
        "Sua vila foi invadida por orcs extremamente ferozes, eles mataram todas as pessoas da sua vila e você foi o único sobrivente, tornando-se assim, um caçador.",
        "Você viu inúmeras pessoa morrendo na sua frente e não pode fazer nada. Desde então, você prometeu não deixar mais ninguém morrer na sua frente.",
        "Seu pai era um ferreiro renomado que acabou morrendo, isso te deixou um legado gigantesco e você decidiu carrega-lo com toda sua alma.",
        "O rei te tirou da rua e te deu um serviço, desde então você se tornou um guarda real. Ele é uma inspiração e um pai para você, então você jurou sempre protege-lo.",
    };

    string historias[limiteDeOcupacao] = {
        "Depois de todo o ocorrido, você começou uma aventura em busca de conquistar o palácio Orc, matar o Orc rei e tomar suas terras, assim, escravizando todos os guerreiros e fazendo-os passar pelo que você passou.",
        "Sua jornada se incia com a busca em se tornar o maior médio de todo continente, explorando horizontes desconhecidos que abrigam inúmeras medicinas inovadoras, algo que te ajudará no seu objetivo.",
        "Você iniciou uma aventura em busca de se tornar o maior ferreiro do continente, indo em busca de ferreiros renomados e aprendendo cada vez mais.",
        "O rei morreu e você procura vingança, iniciando assim, uma busca contínua pelo assassino de 'seu pai'",
    };
    
    cout <<  "Informe seu nome." << endl;
    cin >> nome;
    cin.ignore();
    cout << "Seu nome foi definido como " << nome << "\n" << endl;
    
    cout << "Quantos anos você tem?" << endl;
    cin >> idade;
    cin.ignore();
    cout << "Você tem " << idade << " anos" << "\n" << endl;
    
    cout << "Descreva a aparência do seu personagem." << endl;
    getline(cin,aparencia);
    cout << "Sua aparencia foi definida como: " << aparencia << "\n" << endl;

    cout <<  "Informe seu Sexo." << endl;
    cin >> sexo;
    cin.ignore();
    cout << "Seu sexo foi definido como " << sexo << "\n" << endl;

    cout <<  "Escolha uma das segintes ocupações." << endl;
    for (int i = 0; i < limiteDeOcupacao; ++i){
        cout << "Digite" << " (" << i << ") para " << ocupacoes[i] << endl;
    }
    cin >> ocupacaoEscolhida;
    historia = historias[ocupacaoEscolhida];
    ocupacao = ocupacoes[ocupacaoEscolhida];
    motivacao = motivacoes[ocupacaoEscolhida];
    estiloDeLuta = estilosDeLuta[ocupacaoEscolhida];


    cout << "Sua ocupação foi definida como " << ocupacao << endl;

    classe = classes[gerarClasseNum];
    classeSocial = classesSocial[gerarClasseSNum];
    espadaDoPlayer = espadas[gerarClasseSNum];
    cout << "Gerando atributos..." << "\n" << endl;
    // Configurações de atributos
    if (ocupacao == "Caçador"){
        baseStats[0] += 4; //força
        baseStats[4] += 3; //sabedoria
        baseStats[2] += 5; //iteligencia
        baseStats[3] += 8; //perssuasã
    }else if(classe == "Médico"){
        baseStats[2] += 5; //iteligencia
        baseStats[4] += 8; //sabedoria
        baseStats[2] += 5; //iteligencia
    }else if(classe == "Ferriero"){
        baseStats[0] += 3; //força
        baseStats[2] += 2; //iteligencia
        baseStats[1] += 5; //destreza
    }else if(classe == "Guarda Real"){
        baseStats[0] += 3; //força
        baseStats[4] += 5; //sabedoria
        baseStats[3] += 3; //perssuasã
        baseStats[5] += 2; //carisma
    }; 
    if (classe == "Assassino"){
        baseStats[0] += 10; //força
        baseStats[1] += 6; //destreza
        baseStats[2] += 5; //iteligencia
        baseStats[3] += 10; //perssuasão
        baseStats[4] += 8; //sabedoria
        baseStats[5] += 6; //carisma
    }else if(classe == "Berserk"){
        baseStats[0] += 10; //força
        baseStats[1] += 10; //destreza
        baseStats[2] += 5; //iteligencia
        baseStats[3] += 6; //perssuasão
        baseStats[4] += 8; //sabedoria
        baseStats[5] += 3; //carisma
    }else if(classe == "Guerreiro"){
        baseStats[0] += 9; //força
        baseStats[1] += 8; //destreza
        baseStats[2] += 4; //iteligencia
        baseStats[3] += 6; //perssuasão
        baseStats[4] += 7; //sabedoria
        baseStats[5] += 10; //carisma
    }else if(classe == "Mago"){
        baseStats[0] += 5; //força
        baseStats[1] += 7; //destreza
        baseStats[2] += 10; //iteligencia
        baseStats[3] += 10; //perssuasão
        baseStats[4] += 10; //sabedoria
        baseStats[5] += 9; //carisma
    }else if(classe == "Curandeiro"){
        baseStats[0] += 2; //força
        baseStats[1] += 6; //destreza
        baseStats[2] += 8; //iteligencia
        baseStats[3] += 8; //perssuasão
        baseStats[4] += 10; //sabedoria
        baseStats[5] += 10; //carisma
    };
    //--adicionar tempo
    cout << "Sua espada foi definida para: " << espadaDoPlayer << endl;
    cout << "Seu estilo de luta foi definida para: " << estiloDeLuta << endl;
    cout << "Sua classe foi definida para: " << classe << endl;
    cout << "Sua classe social foi definida para: " << classeSocial << endl;

    cout << "\n" << "Seus status são:" << endl;
    for (int j = 0; j < qStats; ++j){
        cout << statusName[j] << baseStats[j] << endl;
    };

    cout << "\n" << "Sua motivação de vida é: " << "\n" << motivacao << "\n" << endl;
    
    cout << "Sua jornada iniciou-se:" << "\n" << historia << "\n" << endl;
}