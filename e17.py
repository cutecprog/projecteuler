# If the numbers 1 to 5 are written out in words: one, two, three, four, five,
# then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out
# in words, how many letters would be used?
# 
# Note: Do not count spaces or hyphens. For example, 342 (three hundred and
# forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
# letters. The use of "and" when writing out numbers is in compliance with
# British usage.

length = 0

length += len("one")    * 9
length += len("two")    * 9
length += len("three")  * 9
length += len("four")   * 9
length += len("five")   * 9
length += len("six")    * 9
length += len("seven")  * 9
length += len("eight")  * 9
length += len("nine")   * 9

length += len("ten")
length += len("eleven")
length += len("twelve")
length += len("thirteen")
length += len("fourteen")
length += len("fifteen")
length += len("sixteen")
length += len("seventeen")
length += len("eighteen")
length += len("nineteen")

length += len("twenty")  * 10
length += len("thirty")  * 10
length += len("fourty")  * 10
length += len("fifty")   * 10
length += len("sixty")   * 10
length += len("seventy") * 10
length += len("eighty")  * 10
length += len("ninety")  * 10


length += len("hundred") * 900
length += len("one")    * 100
length += len("two")    * 100
length += len("three")  * 100
length += len("four")   * 100
length += len("five")   * 100
length += len("six")    * 100
length += len("seven")  * 100
length += len("eight")  * 100
length += len("nine")   * 100

length += len("and")    * 99 * 9
length += len("onethousand")

print length
