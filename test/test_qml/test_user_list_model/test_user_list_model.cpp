#include "test_user_list_model.h"
#include "user.h"

TestUserListModel::TestUserListModel()
{
    m_testUserListModel.append(User("3600000000","Ivan"));
    m_testUserListModel.append(User("3700000000","Error"));

    m_userListModel.setUserlist(m_testUserListModel);
}


void TestUserListModel::qmlEngineAvailable(QQmlEngine *engine)
{
    engine->rootContext()->setContextProperty("userListModel", &m_userListModel);
}

QUICK_TEST_MAIN_WITH_SETUP(test_user_list_model,TestUserListModel)
