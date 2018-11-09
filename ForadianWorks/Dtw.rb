class Dtw
  @@a = {1 => "First",  2 => "Second",  3 => "Third",  4 => "Fourth",  5 => "Fifth",  6 => "Sixth",  7 => "Seventh",  8 => "Eight",  9 => "Nineth",
  10 => "Tenth",  11 => "Eleventh",  12 => "Twelveth",  13 => "Thirteenth",  14 => "Fourteenth",  15 => "Fifteenth",  16 => "Sixteenth",  17 => "Seventeeth",
  18 => "Eighteenth",  19 => "Nineteeth",  "014" => "FOURTEEN"}
  @@y ={1 => "ONE", 2 => "TWO", 3 => "THREE", 4 => "FOUR", 5 => "FIVE"}
  @@b = {0 => "ZERO",  1 => "ONE",  2 => "TWENTY",  3 => "THIRTY",  4 => "FORTY",  5 => "FIFTY",  6 => "SIXTY",  7 => "SEVENTY",  8 => "EIGHTY",  9 => "NINETY"}
  @@m = {1 => "January",  2 => "February",  3 => "March",  4 => "April",  5 => "May",  6 => "June",  7 => "July",  8 => "Augest",  9 => "September", 10 => "October", 11 => "November", 12 => "Dcember"}
  @@c = ["HUNDRED",  "THOUSAND"]
  def input_method
    puts "Enter the Date in Format (dd-mm-yyyy)::"
    @date = gets.to_s
    puts "#{@date}"
    @date_to_type = @date.split("-")
    puts "#{@date_to_type[1]}"
    date(@date_to_type[0])
    month(@date_to_type[1])
    year(@date_to_type[2])
  end

  def date(dt)
    @dtnew = dt.to_i
    if @dtnew >= 20
      print "#{@@b[@dtnew/10]}"
      print " #{@@a[@dtnew%10]}" if  @dtnew%10 != 0
    else
      print "#{@@a[@dtnew]}"
    end
  end

  def month(mt)
    @dtnew = mt.to_i
    print "-#{@@m[@dtnew]}"
  end

  def year(yr)
    @dtnew = yr.to_i
    print "-#{@@y[@dtnew/1000]} #{@@c[1]}"
  end
end



ob = Dtw.new

ob.input_method
