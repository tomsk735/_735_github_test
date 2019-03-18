# _735_github_test
Modification file
Каждому студенту из 735 группы внести правку в файл `_735_list.h`, сопроводив ее сообщением (commit message).

## Установка клиента git
Windows
1. Скачайте installer для windows https://git-scm.com/downloads
2. Запустите installer. Укажите путь, куда установить git. Пропишите этот путь в переменную `PATH`.
3. Запустите консоль. Убедитесь, что команда `git` доступна.

Ubuntu
Выполните команду:
```
sudo apt install git
```

## Настройка git

Настройте username и email в git клиенте
```
git config user.name "<your username>"
git config user.email <your email>
``` 

## Шаги выполнения задания

1. Скачайте репозиторий:
```
git clone https://github.com/BIGHERR/_735_github_test
```
2. Создайте свою ветку:
```
git checkout -b <Название ветки>
```
3. Измените файл `_735_list.h`: Впишите своё имя вместо `"=============================="`.
4. Добавьте изменения в комит.
```
git add _735_list.h
```
5. Создайте комит с измениями:
```
git commit -m "Ваше сообщения"
```
6. Запуште измениния в удаленный репозиторий.
```
git push
```
7. Откройте pull-request. И назначьте ревьюера пользователя `BIGHERR`.
