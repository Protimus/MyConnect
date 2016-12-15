/* Métodos para realizar consultas padrões em banco de dados
** @author: Rafael P. da Costa Gorges
** @date: 12/15/2016
**/

#include "connector.cpp"

/* Função para execução de uma query (consulta) ao banco
-  Realiza a consulta do horário atual */
char MySQLConnector::getSysdate() {
    try {
        char const *consulta = "SELECT SYSDATE() as sysdate"; // Estrutura do SELECT para consulta
        //this->conecta(); // Realiza conexão para execução
        res = stmt->executeQuery(consulta); // Realiza execução da consulta
        while (res->next()) {
            res->getString("sysdate"); // Imprime o resultado da query
            cout << "consulta = '" << res->getString("sysdate") << "'" << endl;
        }
        //this->desconecta(); // Uso de desconexão após execução
    } catch(sql::SQLException &e) {
        cout << ("Falha ao fechar conexao com o banco" ,e.what()); // Exibe mensagem de erro para exceção      
        return EXIT_FAILURE;
    }
}