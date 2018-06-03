puts 100
100.times do
  d = rand(10..20)
  cs = ['C', 'S']
  line = 30.times.reduce('') do |accum, i|
    accum += cs.sample
    accum
  end
  puts "#{d} #{line}"
end
