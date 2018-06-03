import sys

def solve(lower, upper, max_trial):
    if max_trial < 1:
        exit(2)

    avg = (lower + upper) / 2
    guess = max([lower + 1, avg])
    print guess
    sys.stdout.flush()

    resp = sys.stdin.readline().rstrip()
    print >> sys.stderr, 'guess: {guess}, resp: {resp}'.format(guess=guess, resp=resp)
    if resp == 'CORRECT':
        return 0
    elif resp == 'TOO_SMALL':
        solve(guess, upper, max_trial - 1) 
    elif resp == 'TOO_BIG':
        solve(lower, guess - 1, max_trial - 1)
    elif resp == 'WRONG_ANSWER':
        exit(1)

n_case = int(sys.stdin.readline().rstrip())
for i in range(0, n_case):
    a, b = [int(str) for str in sys.stdin.readline().rstrip().split()]
    n = int(sys.stdin.readline().rstrip())
    print >> sys.stderr, 'a: {a}, b: {b}, n: {n}'.format(a=a, b=b, n=n)
    solve(a, b, n)
