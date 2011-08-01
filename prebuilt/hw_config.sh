# lv5219lg LMU configuration
dev=/sys/class/leds/lv5219lg:mled
echo 1 > $dev/als_enable
echo 0 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 > $dev/als_config
echo 1 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 > $dev/als_config
echo 2 7 7 7 7 7 7 7 7 7 15 15 15 15 15 15 15 > $dev/als_config
echo 3 7 7 11 11 11 15 15 15 15 19 19 19 19 23 23 23 > $dev/als_config
echo 4 11 11 11 15 15 19 19 19 19 23 23 23 23 27 27 31 > $dev/als_config
echo 5 11 11 15 15 15 19 23 23 23 31 31 35 35 43 43 51 > $dev/als_config
echo 6 11 15 15 15 19 19 23 23 23 31 45 45 51 51 67 67 > $dev/als_config
echo 7 15 19 19 19 23 23 31 31 43 43 51 51 67 67 83 83 > $dev/als_config
echo 8 19 19 23 23 31 31 43 43 51 51 67 67 83 83 95 103 > $dev/als_config
echo 9 27 35 35 43 43 51 51 59 59 67 75 75 91 91 99 103 > $dev/als_config
echo 10 43 43 51 51 59 59 67 67 75 75 83 83 95 95 103 107 > $dev/als_config
echo 11 55 59 59 67 67 75 75 83 83 91 91 99 99 103 103 111 > $dev/als_config
echo 12 67 67 75 75 83 83 91 91 95 95 99 103 103 107 107 115 > $dev/als_config
echo 13 79 83 83 87 87 95 95 99 99 103 103 107 107 111 111 115 > $dev/als_config
echo 14 99 99 107 107 107 107 111 111 111 111 115 115 115 115 119 119 > $dev/als_config
echo 15 115 115 115 115 115 115 115 115 115 123 123 123 123 123 123 123 > $dev/als_config
echo 16 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 > $dev/als_config

