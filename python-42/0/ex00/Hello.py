ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}


ft_list[1] = "World!"

ft_tuple = list(ft_tuple)
ft_tuple[1] = "United Arab Emirates!"
ft_tuple = tuple(ft_tuple)

# Sets are unordered
ft_set.remove("tutu!")
ft_set.add("Abu Dhabi!")

ft_dict["Hello"] = "42 Abu Dhabi!"

print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)