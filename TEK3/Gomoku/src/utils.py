from sys import stdin, stdout


def pipeOut(what):
    """write a line to sys.stdout"""
    ret = len(what)
    print(what)
    stdout.flush()


def safeInt(x):
    try:
        z = int(x)
        return z
    except:
        return None
