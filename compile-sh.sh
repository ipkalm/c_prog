:

### скрипт лаба из курсов eltex ###
# 5.3.1. Написать и отладить сценарий shell для открытия в редакторе vi\
# указанного с-файла, компиляции его после выхода из редактора, запроса\
# на запуск исполняемой программы (в зависимости от наличия ошибок компиляции),\
# при отказе от запуска – перехода в редактор, по окончании работы программы –\
# запроса на завершение сценария.
###                             ###

name=app

if [ -z $1 ]; then # -z означает что файл пустой
    echo "Вы не выбрали файл исходников на Си"
    exit 0
fi

echo "1. Сейчас откроется редактор vi для редактирования исходника" $1
echo ""
# sleep 5
vi $1

echo "2. Редактирование окончилось"
echo ""

while :
do
    if gcc -Wall -o $name $1; then
	echo "Компиляция прошла успешно, поздравляю"
	echo ""
	while :
	do
	    echo "3. Запустить исполняемый файл "$name" ? (введите y или n)"
	    echo "При выборе n откроется редактор vi для редактирования исходника" $1
	    echo "При выборе y запустится скомпилированное приложение" $name
	    echo "Так что y/n ?"
	    read x
	    case $x in
		y)
		    while :
		    do
			./$name
			echo "запустить приложение" $name "еще раз? (y или n)"
			while :
			do
			    read y
			    case $y in
				y)
				    break
				    ;;
				n)
				    echo "Пока"
				    exit 0
				    ;;
				*)
				    echo "Некорретный ответ. введите y или n"
				    continue 
				    ;;
			    esac
			done
		    done
		    ;;
		n)
		    vi $1
		    ;;
		*)
		    echo "Нет, нужно ввести y или n"
		    echo ""
		    continue
		    ;;
	    esac
	done
    else
	echo "Произошли ошибки во время компиляции, открыть редактор ?"
	while :
	do
	    read x
	    case $x in
		y)
		    vi $1
		    break
		    ;;
		n)
		    exit 0
		    ;;
		*)
		    echo "Введены не верные значениея, давай-ка или y, или n"
		    continue
		    ;;
	    esac
	done
    fi
done

exit 0
