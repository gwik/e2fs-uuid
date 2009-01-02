require File.dirname(__FILE__) + '/../ext/uuid_ext'

module E2FS
  
  class UUID
    
    FORMATS = {
      :nosep => '%02x' * 16,
      :default => "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
    }
    
    def initialize
      @ary = self.class.generate.freeze
    end
    
    def to_s(format_string=:default)
      format(FORMATS[format_string], *@ary)
    end
    
    def to_a
      @ary.dup
    end
    
  end
  
end
