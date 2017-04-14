start_date <- as.Date("01-01-1901", format="%d-%m-%Y")
end_date <- as.Date("31-12-2000", format="%d-%m-%Y")

day_as_int <- function(date) {
    return(as.integer(format(date, "%d")))
}

sunday_count <- 0
date <- start_date

while (date != end_date) {
    if (day_as_int(date) == 1 && weekdays(date) == "Sunday") {
        sunday_count = sunday_count + 1
    }
    date = date + 1
}

print(sunday_count)
