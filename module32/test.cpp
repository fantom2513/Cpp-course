#include "gtest/gtest.h"
#include <iostream>

class DBConnection
{
public:
    DBConnection()
    {}
    virtual ~DBConnection()
    {}

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void execQuery() = 0;
};

class ClassThatUsesDB
{
public:
    ClassThatUsesDB()
    {
        std::cout << "ClassThatUsesDB()" << std::endl;
    }

    ~ClassThatUsesDB()
    {
        std::cout << "~ClassThatUsesDB()" << std::endl;
    }

public:
    DBConnection* connection;

    void openConnection() {
        connection->open();
    }
    void useConnection() {
        connection->execQuery();
    }
    void closeConnection() {
        connection->close();
    }
};

// определяем класс мок-объекта на основе нужного нам интерфейса
class MockDBConnection : public DBConnection {
public:
    // пользуемся макросами GTest для определения мок-методов в объекте
    MOCK_METHOD(void, open, (), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(void, execQuery, (), (override));
};

//Тест-кейс
TEST(MyTestSuite, testcase)
{
    MockDBConnection connection;

    EXPECT_CALL(connection, open).Times(1);
    EXPECT_CALL(connection, execQuery).Times(1);
    EXPECT_CALL(connection, close).Times(1);    

    connection.open();
    connection.execQuery();
    connection.close();
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}