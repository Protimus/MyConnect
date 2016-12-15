/* Métodos para fazer conexão com MySQL C++ Connector
** @author: Rafael P. da Costa Gorges
** @date: 12/15/2016
**/

#include "connector.h"

/* Construtor */
MySQLConnector::MySQLConnector() {
}
/* Destrutor */
MySQLConnector::~MySQLConnector() {
}

/* Função para conexão ao MySQL */
bool MySQLConnector::conecta() {
    try {
        driver = get_driver_instance(); // Cria uma nova instância com o driver do MySQL
        con = driver->connect(MyAddress, MyUser, MyPass); // Cria uma conexão com o driver atavés das informações de conexão
        con->setSchema(MyDB); // Conecta ao banco de dados
        stmt = con->createStatement(); // Cria um estado de conexão
    } catch (sql::SQLException &e) { 
        cout << "# ERRO: SQLException em " << __FILE__; // Capura a exceção
        cout << "(" << __FUNCTION__ << ") na linha " << __LINE__ << endl; // Captura a linha que está com erro
        cout << "# ERRO: " << e.what(); // Uso do what para retorno mais abrangente
        cout << " (MySQL Erro: " << e.getErrorCode(); // Retorna código de erro do MySQL
        cout << ", SQLState: " << e.getSQLState() << " )" << endl; // Retorna estado do MySQL
        return EXIT_FAILURE; // Realiza saída em caso de erro
    }
}

/* Função para desconectar do MySQL */ 
bool MySQLConnector::desconecta() {
    try {
        this->con->close(); // Fecha a conexão com o ponteiro de conexão
        delete this->con; // Deleta o ponteiro de conexão
        this->driver->threadEnd(); // Finaliza thred de instância com o driver
        return EXIT_SUCCESS; 
    } catch(sql::SQLException &e) {
        cout << ("Falha ao fechar conexao com o banco" ,e.what()); // Exibe mensagem de erro para exceção      
        return EXIT_FAILURE;
    }
}