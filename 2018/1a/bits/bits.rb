class Cashier
  attr_reader :max_items, :s_time, :p_time
  def initialize(max_items, s_time, p_time)
    @max_items = max_items
    @s_time = s_time
    @p_time = p_time
  end

  
end

def solve(cashiers, r, b)
end

n_cases = STDIN.gets.chomp.to_i
n_cases.times do |i|
  r, b, c = STDIN.gets.chomp.split(' ')
  cashiers = c.times.map do
    m, x, p = STDIN.gets.chomp.split(' ').map(&:to_i)
    Cashier.new(m, x, p)
  end

  ans = solve(chashiers, r, b)
  puts "Case ##{i+1}: #{ans}"
end
