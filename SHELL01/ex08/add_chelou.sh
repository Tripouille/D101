echo "obase=13; $(($(echo "ibase=5; $(echo $FT_NBR1 | tr ''\''\\\"?!' 01234)" | bc) + $(echo "ibase=5; $(echo $FT_NBR2 | tr mrdoc 01234)" | bc)))" | bc | tr 0123456789ABC "gtaio luSnemf"
