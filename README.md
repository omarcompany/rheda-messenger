#   **RHEDA-MESSENGER**
***
```bash
git clone git@github.com:omarcompany/rheda-messenger.git
qmake -v
qmake -r
make
```

## Сборка под Android

Для сборки проекта необходим проект OpenSSL. В версии Qt выше 5.14.1 его можно скачать в настройке комплекта под андроид (более подробно см. wiki)
Если вы используете Qt старых версий, взять исходники можно здесь https://github.com/KDAB/android_openssl
В application.pro есть такая строка:
```bash
android: include($$(HOME)/Android/Sdk/android_openssl/openssl.pri)
```
Необходимо изменить путь к openssl.pri, на ваш вариант
***

### Сборка под Linux
Не требуется никаких специальных настроек
***
### Сборка под Windows
To do!!!


