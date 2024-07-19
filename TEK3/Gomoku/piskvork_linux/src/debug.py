class Debug:
    def __init__(self):
        self.DEBUG_LOGFILE = "/tmp/pbrain-pyrandom.log"
        self.DEBUG_LOGFILE2 = "/tmp/pbrain-pyrandom2.log"
        with open(self.DEBUG_LOGFILE, "w") as _:
            pass
        with open(self.DEBUG_LOGFILE2, "w") as _:
            pass

    def log(self, msg, file=1):
        file = self.DEBUG_LOGFILE2 if file == 2 else self.DEBUG_LOGFILE
        with open(file, "a") as f:
            f.write(msg.__repr__() + "\n")

    def logTraceBack(self):
        import traceback

        traceback.print_exc(file=self.file)
        self.file.flush()
        raise
