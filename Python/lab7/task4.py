# Вы - программист в компании, занимающейся онлайн-рекомендациями. Пользователи оставляют
# отзывы о различных товарах и услугах. Иногда пользователи пишут “не плохо”, но на самом деле
# хотят сказать “хорошо”. Чтобы сделать отзывы более позитивными, вам нужно создать программу,
# которая будет автоматически исправлять эти фразы.
# Замены:
# не плохой - хороший
# не плоха - хороша

s = input("Введите текстовый отзыв:")
if "не плохой" in s:
    s = s.replace("не плохой", "хороший")
elif "не плоха" in s:
    s = s.replace("не плоха", "хороша")
print(s)