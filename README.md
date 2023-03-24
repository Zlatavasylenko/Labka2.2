# Labka2.2
Approximate function calculation(version2)
Версія 2
Користувач задає x і крок h, де a < x < b, h > 0. Як і у версії 1, програма має ігнорувати недопустимі значення x за межами інтервалу (a; b), повідомляючи про недопустимість і запрошуючи до повторного введення, поки користувач не введе допустиме значення. Запрошення до кожного введення x повинно містити межі інтервалу (a; b), якому має належати аргумент, запрошення до введення h – підказку, що h має бути більше 0.
Програма починає з аргументу x і збільшує його з кроком h, тобто обробляє аргументи x, x+h, x+2h, …, поки не досягне кінця інтервалу b (значення f(b) не обчислювати!). Для кожного аргументу програма виводить чотири числа: аргумент, два значення функції та їх різницю, вказані у версії 1.
Результати виводяться «сторінками». Перший рядок сторінки є заголовком і містить позначення:
x, f_lib(x), f_sum(x), difference
Наступні 10 рядків – по чотири відповідних числа, вирівняних за правим краєм із позначеннями в заголовку.
Для кожного аргументу та способу обчислення значення функції обчислюється тільки один раз.
Після виведення кожної «сторінки», крім останньої, програма виводить запит, чи продовжувати, та підказку, що клавіша Esc означає закінчення обробки заданого x, а будь-яка інша – продовження. Остання «сторінка» може мати менше 10 рядків, але не менше одного.
Робота програми припиняється тільки після натискання на Ctrl-C. Якщо x або h не введено через сторонні символи, то програма виводить повідомлення <<<WRONG DATA>>> та повертає користувача до введення потрібного числа.
Вимоги до виконання
1.Додати функцію введення дійсного числа inputD() без параметрів, яка запрошує до введення дійсного числа та повертає введене дійсне число, або, в разі помилкових даних кидає виняток цілого типу.
2. Додати функцію отримання дійсного числа getDouble() без параметрів, яка повертає дійсне значення, отримане з виклику функції inputD. Якщо у виклику getDouble з’являється виняток цілого типу, то вона перехоплює його, відновлює працездатність потоку введення, пропускає символи до кінця рядка введення, виводить повідомлення <<<WRONG DATA>>> та повторює виклик функції inputD. Пропустити символи до кінця рядка за допомогою бібліотечної функції get(), не використовуючи sync() або ignore().
3. Переробити функцію getArg. Її параметрами мають бути кінці інтервалу, вона повертає дійсне число в його межах. Вона отримує дійсне число від функції getDouble і повертає користувача до введення, якщо число за межами інтервалу.
4. Додати функцію getIncr() введення кроку h. Вона повертає дійсне число, отримане від функції getDouble (якщо воно не додатне, то функція повертає «стандартне» значення 10–2).
5. Змінити функцію calcSum, яка тепер має тільки один параметр і не обчислює кількість доданків.
6. Переробити функції putHeader та putResult, враховуючи, що в рядку виводиться чотири числа.
7. Додати функцію processXH з параметрами x і h: викликаючи функції обчислення, функції putHeader та putResult, вона виводить «сторінки», зазначені вище. За допомогою функції nextPage (див. наступний пункт) вона визначає, чи продовжувати роботу після чергової сторінки.
8. Додати функцію nextPage(), яка викликається після виведення «сторінки» результатів. Вона виводить запит, чи продовжувати виведення, отримує відповідь (Esc або інша клавіша), і повертає булеву ознаку продовження. Для того, щоб визначити, чи було натиснуто клавішу Esc, скористатися бібліотечною функцією get() або _getch().