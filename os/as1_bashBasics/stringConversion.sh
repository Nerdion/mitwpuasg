read name
echo $name | tr '[ a-z ]' '[ A-Z ]'

var2=${name^^[aeiou]}
echo $var2
