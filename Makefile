BAZEL ?= ./bazelisk

voidstar: $(BAZEL)
	$(BAZEL) build $@

$(BAZEL):
	curl -fsSLo $@ $$( \
	  curl --silent --location --head --output /dev/null --write-out '%{url_effective}' -- https://github.com/bazelbuild/bazelisk/releases/latest \
	  | sed "s%/tag/%/download/%;s%$$%/bazelisk-linux-$$(dpkg --print-architecture)%" )
	chmod +x $@

install: DESTDIR ?= .
install:
	cp -v bazel-bin/voidstar/voidstar $(DESTDIR)/

debug:
	snapcraft
