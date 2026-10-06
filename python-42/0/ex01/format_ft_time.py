import datetime

time_now = datetime.datetime.now()
timestamp = time_now.timestamp()
print("Seconds since January 1, 1970:",
        "{:,.4f}".format(timestamp),
        "or {:.2e} in scientific notation".format(timestamp))
print(time_now.strftime('%b %d %Y'))
