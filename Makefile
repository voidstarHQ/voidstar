BAZEL = bazelisk

voidstar: $(BAZEL)
	$(BAZEL) build $@

$(BAZEL):
	command -v bazelisk >/dev/null || curl -fsSLo $@ https://github.com/bazelbuild/bazelisk/releases/download/v1.6.1/bazelisk-linux-amd64 && chmod +x $@

install: DESTDIR ?= .
install:
	cp -v bazel-bin/voidstar/voidstar $(DESTDIR)/

debug:
	snapcraft
